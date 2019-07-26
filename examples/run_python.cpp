//
// Created by coolivie on 7/25/19.
//
#include <unistd.h>
#include <spawn.h>

#include <vector>
#include <cstdio>
#include <cstdlib>

static const char *get_python() {
  const char *pp = getenv("PYTHON");
  if (pp == nullptr || *pp == '\0') {
    return "/usr/bin/python3";
  }
  return pp;
}

int main(int argc, char **argv) {
  fprintf(stderr, "PYTHONPATH=%s\n", getenv("PYTHONPATH"));

  std::vector<const char *> args;
  args.push_back(get_python());
  for (int i = 1; i < argc; ++i) {
    args.push_back(argv[i]);
  }
  args.push_back(nullptr);
  return execv(args[0], (char * const *)&args[0]);
}