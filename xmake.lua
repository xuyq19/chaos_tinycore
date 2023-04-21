set_project("chaos")
set_version("0.1.0")

set_languages("c99", "cxx11")
set_warnings("all", "error")

set_plat("riscv")
set_arch("riscv64imac")

set_toolchains("riscv64-unknown-elf-")

add_rules("mode.debug", "mode.release")

target("chaos")
    set_kind("binary")
    add_files("code/*.c")
    add_includedirs("code/include/*.h")