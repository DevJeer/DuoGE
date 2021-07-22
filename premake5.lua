workspace "Duo"             --解决方案的名称
    architecture "x64"      --支持的位数

    configurations
    {
        "Debug",
        "Release",          
        "Dist"              --发布版本
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Duo"
    location "Duo"
    kind    "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}") --..在lua中表示连接字符串
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",     --**表示添加当前文件夹以及子文件夹下的所有.h文件
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"  --filter表示详细的设置
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "DUO_PLATFORM_WINDOWS",
            "DUO_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .."/Sandbox") --这里是将生成的dll拷贝到Sandbox目录下
        }

    filter "configurations:Debug"
        defines "DUO_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "DUO_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "DUO_DIST"
        optimize "On"
    
project "Sandbox"
    location "Sandbox"
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
        "Duo/vendor/spdlog/include",
        "Duo/src"
    }

    links
    {
        "Duo"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "DUO_PLATFORM_WINDOWS"
        }
    filter "configurations:Debug"
        defines "DUO_DEBUG"
        symbols "On"
    filter "configurations:Release"
        defines "DUO_RELEASE"
        optimize "On"
    filter "configurations:Dist"
        defines "DUO_DIST"
        optimize "On"
