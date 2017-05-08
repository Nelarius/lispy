workspace "lisp"
    if _ACTION then
        location("build/".._ACTION)
    end

    configurations { "Debug", "Release" }

    architecture "x86_64"

    filter "configurations:Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

    filter "action:vs*"
        defines { "_CRT_SECURE_NO_WARNINGS" }

    project "lispy"
        language "C"
        kind "ConsoleApp"
        targetdir "bin"
        files { "src/**.c", "src/**.h" }
        includedirs { "src/" }

        filter "action:gmake"
            links { "edit" }
