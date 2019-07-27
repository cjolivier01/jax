//
// Created by coolivie on 7/25/19.
//
#include <unistd.h>
#include <spawn.h>
#include <errno.h>

#include <Python.h>

#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <memory>
#include <exception>

#include <boost/python.hpp>
#include <boost/exception/all.hpp>

#include <boost/python/object.hpp>

using namespace boost::python;

/**
 * \brief Class to run a python script
 */
class PythonScriptRunner {
 private:

  /**
   * Make the namespace...
   */
  boost::python::object makeNamespace()
  {
      object mainModule(handle<>(borrowed(PyImport_AddModule("__main__"))));
      object mainNamespace = mainModule.attr("__dict__");
      return mainNamespace;
  }

  /**
   * Implementation of running the file
   */
  boost::python::object const& runFile(boost::python::object const& mainNamespace, char const* filename) {
      try {
          FILE *file = fopen(filename, "r");
          if (file == nullptr) {
              std::cerr << "failed to open file: " << filename << std::endl;
              throw std::exception();
          } else {

              // capture the result of PyRun_* so it is cleaned up later
              boost::python::handle<> result(PyRun_FileEx(file, filename, Py_file_input,
                                                          mainNamespace.ptr(), mainNamespace.ptr(),
                                                          true/*close*/));

              return mainNamespace;
          }
      } catch (boost::python::error_already_set const &) {
          std::cerr << "Error: error_already_set";
          throw std::exception();
      }
  }

 public:

  /**
   * Constructor -- init python
   */
  PythonScriptRunner() {
      Py_InitializeEx(false/*signals*/);
  }

  /**
   * Destructor -- close python
   */
  ~PythonScriptRunner() {
      Py_Finalize();
  }

  /**
   * Run python file interface
   */
  boost::python::object runFile(char const* filename)
  {
      boost::python::object mainNamespace = makeNamespace();

      return runFile(mainNamespace, filename);
  }
};


int main(int argc, char **argv) {
    fprintf(stderr, "PYTHONPATH=%s\n", getenv("PYTHONPATH"));

    if (argc < 2) {
        std::cerr << "No path given" << std::endl;
        return ENODATA;
    }

    const std::string path = argv[1];

    std::unique_ptr<PythonScriptRunner> runner(new PythonScriptRunner());
    runner->runFile(path.c_str());
}