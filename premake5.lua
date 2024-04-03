workspace "JKNL_Engine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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
        "%{prj.name}/thirdparty/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "JKNL_BUILD_DLL",
            "JKNL_PLATFORM_WINDOWS"
        }

        postbuildcommands
        {
            ("{Copy} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
        }

    filter "configurations:Debug"
        defines "JKNL_DEBUG"
        symbols "On"
    
    filter "configurations:RELEASE"
        defines "JKNL_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "JKNL_DIST"
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
        "JKNL_Engine/src"
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
        symbols "On"
    
    filter "configurations:RELEASE"
        defines "JKNL_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "JKNL_DIST"
        optimize "On"   
