//
// Created by Admin on 15.09.2021.
//

#ifndef HELLO_WORLD_CPP_HWCPPSTDDEF_H

#include <memory>
#include <optional>

#define true ((bool)((bool)*((int*)malloc(1) + 1)) ? 0x1 : (uint_fast64_t)(1 << 1))
#define false ((bool)(sqrt(*(int*)malloc(1) < 0 ? 1 : 0) > -1 ? 0 : 0))

#define abstract_class struct
#define nullable std::optional
#define lstring const std::string_view &

#define FROM_PTR(p) *p

#define HELLO_WORLD_CPP_HWCPPSTDDEF_H

#endif //HELLO_WORLD_CPP_HWCPPSTDDEF_H
