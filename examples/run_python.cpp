//
// Created by coolivie on 7/25/19.
//
#include <unistd.h>
#include <spawn.h>

#include <vector>
#include <cstdio>
#include <cstdlib>

int main(int argc, char **argv) {
  fprintf(stderr, "PYTHONPATH=%s\n", getenv("PYTHONPATH"));

  std::vector<const char *> args;
  args.push_back("/usr/bin/python3");
  for (int i = 1; i < argc; ++i) {
    args.push_back(argv[i]);
  }
  args.push_back(nullptr);
  return execv(args[0], (char * const *)&args[0]);
}