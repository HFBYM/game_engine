workspace "game_engine"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" }
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
IncludeDir = {}
IncludeDir["GLFW"] = "engine/vendor/glfw/include"
include "engine/vendor/glfw"
project "engine"
    location "engine"
    kind "SharedLib"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    files{"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp", "%{IncludeDir.GLFW}"}
    links{"glfw", "opengl32.lib"}
    includedirs{"%{prj.name}/vendor/spdlog/include", "%{prj.name}/src", "%{IncludeDir.GLFW}"}
    pchheader "eg_pch.h"
    pchsource "%{prj.name}/src/eg_pch.cpp"
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        defines{"EG_PLATFORM_WINDOWS","EG_BUILD_DLL",}
        -- postbuildcommands{("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/sandbox")}
        postbuildcommands{"cmd post_build.bat"}
    filter "configurations:Debug"
        defines "EG_DEBUG"
        buildoptions "/MDd"
        symbols "On"
    filter "configurations:Release"
        defines "EG_RELEASE"
        buildoptions "/MD"
        optimize "On"
    filter "configurations:Dist"
        defines "EG_DIST"
        buildoptions "/MD"
        optimize "On"

project "sandbox"
    location "sandbox"
    kind "ConsoleApp"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    files{"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp",}
    includedirs{"engine/vendor/spdlog/include", "engine/src"}
    links("engine")
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        defines{"EG_PLATFORM_WINDOWS",}
    filter "configurations:Debug"
        defines "EG_DEBUG"
        buildoptions "/MDd"
        symbols "On"
    filter "configurations:Release"
        defines "EG_RELEASE"
        buildoptions "/MD"
        optimize "On"
    filter "configurations:Dist"
        defines "EG_DIST"
        buildoptions "/MD"
        optimize "On"
