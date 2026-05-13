set_project("hn-toolkits")
set_version("0.2.2")

set_languages("c23") -- 使用一些C23的新特性，如auto自动推导等。
set_toolchains("clang")

add_rules("mode.debug", "mode.release")

target("hn-toolkits")
    set_kind("binary")
    add_files("src/*.c")
    add_files("src/lib/**.c")
    add_includedirs("include")
    set_warnings("allextra","error")
    set_targetdir("build/$(mode)")

    if is_mode("debug") then
        set_symbols("debug")
        set_optimize("none")
        add_defines("DEBUG")
    end

    if is_mode("release") then
        set_symbols("hidden")
        set_optimize("fastest")
        add_defines("RELEASE")
        set_strip("all")
        set_warnings("none")
        add_defines("RELEASE")
    end

for _, testfile in ipairs(os.files("tests/**/test_*.c")) do
    local name = path.basename(testfile)
    target(name)
        set_default(false)
        set_kind("binary")
        add_includedirs("include")
        add_files("src/lib/**.c")
        add_files(testfile)
        set_warnings("allextra","error")
        set_targetdir("build/tests/" .. name .. "/$(mode)")

    if is_mode("debug") then
        set_symbols("debug")
        set_optimize("none")
        add_defines("DEBUG")
    end

    if is_mode("release") then
        set_symbols("hidden")
        set_optimize("fastest")
        add_defines("RELEASE")
        set_strip("all")
        set_warnings("none")
        add_defines("RELEASE")
    end
end

target("hn-toolkits-lib")
    set_kind("shared")
    add_files("src/lib/**.c")
    add_includedirs("include")
    set_warnings("allextra","error")
    set_targetdir("build/lib/$(mode)")
    if is_mode("debug") then
        set_symbols("debug")
        set_optimize("none")
        add_defines("DEBUG")
    end

    if is_mode("release") then
        set_symbols("hidden")
        set_optimize("fastest")
        add_defines("RELEASE")
        set_strip("all")
        set_warnings("none")
        add_defines("RELEASE")
    end