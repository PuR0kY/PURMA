workspace "PURMA"
	architecture "x64"
  	startproject "Sandbox"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-x64"

project "PURMA"
	location "PURMA"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "purpch.h"
	pchsource "PURMA/src/purpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"PURMA/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PUR_PLATFORM_WINDOWS",
			"PUR_BUILD_DLL"
		}

		buildoptions
		{
			"/utf-8"
		}

		postbuildcommands
		{
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "PUR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PUR_RELEASE"
		optimize "On"

	-- filter { "system:windows", "configurations:Release" }
	-- 	buildoptions "/MT"

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
		"PURMA/vendor/spdlog/include",
		"PURMA/src"
	}

	links
	{
		"PURMA"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PUR_PLATFORM_WINDOWS"
		}

		buildoptions
		{
			"/utf-8"
		}

	filter "configurations:Debug"
		defines "PUR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PUR_RELEASE"
		optimize "On"
