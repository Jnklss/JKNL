workspace "JKNL_Engine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- 包含相对于根文件夹的目录(解决方案目录)
IncludeDir = {}
IncludeDir["GLFW"] = "JKNL_Engine/thirdparty/GLFW/include"

include "JKNL_Engine/thirdparty/GLFW"

project "JKNL_Engine"
    location "JKNL_Engine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/thirdparty/spdlog/include",
        "%{prj.name}/thirdparty/json11",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW"  ,
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "JKNL_BUILD_DLL",
            "JKNL_PLATFORM_WINDOWS",
        }

        postbuildcommands
        {
            ("{Copy} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
        }

    filter "configurations:Debug"
        defines "JKNL_DEBUG"
        staticruntime "off"
        runtime "Debug"
        symbols "On"
    
    filter "configurations:RELEASE"
        defines "JKNL_RELEASE"
        staticruntime "off"
        runtime "Release"
        optimize "On"
    
    filter "configurations:Dist"
        defines "JKNL_DIST"
        staticruntime "off"
        runtime "Release"
        optimize "On"
    

project "SandBox"
    location "SandBox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "JKNL_Engine/thirdparty/spdlog/include",
        "JKNL_Engine/src",
        "JKNL_Engine/thirdparty/json11"
    }

    links
    {
        "JKNL_Engine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "JKNL_PLATFORM_WINDOWS"
        }


    filter "configurations:Debug"
        defines "JKNL_DEBUG"
        staticruntime "off"
        runtime "Debug"
        symbols "On"
    
    filter "configurations:RELEASE"
        defines "JKNL_RELEASE"
        staticruntime "off"
        runtime "Release"
        optimize "On"
    
    filter "configurations:Dist"
        defines "JKNL_DIST"
        staticruntime "off"
        runtime "Release"
        optimize "On"   
