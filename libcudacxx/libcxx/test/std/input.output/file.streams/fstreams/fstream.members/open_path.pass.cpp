//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++98, c++03, c++11, c++14
// XFAIL: windows

// <fstream>

// plate <class charT, class traits = char_traits<charT> >
// class basic_fstream

// void open(const filesystem::path& s, ios_base::openmode mode = ios_base::in|ios_base::out);

#include <fstream>
#include <filesystem>
#include <cassert>
#include "test_macros.h"
#include "platform_support.h"

int main(int, char**) {
  std::filesystem::path p = get_temp_file_name();
  {
    std::fstream stream;
    assert(!stream.is_open());
    stream.open(p,
                std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
    assert(stream.is_open());
    double x = 0;
    stream << 3.25;
    stream.seekg(0);
    stream >> x;
    assert(x == 3.25);
  }
  std::remove(p.c_str());
  {
    std::wfstream stream;
    assert(!stream.is_open());
    stream.open(p,
                std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
    assert(stream.is_open());
    double x = 0;
    stream << 3.25;
    stream.seekg(0);
    stream >> x;
    assert(x == 3.25);
  }
  std::remove(p.c_str());

  return 0;
}
