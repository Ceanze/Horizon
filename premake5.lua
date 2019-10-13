workspace "Horizon"
	architecture "x64"
	startproject "Sandbox"
	language "C++"

	configurations
	{
		"Debug",
		"Release"
	}

	flags
	{
		"MultiProcessorCompile"
	}

	filter "system:windows"
		defines
		{
			"HRZ_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HRZ_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HRZ_RELEASE"
		runtime "Release"
		optimize "on"


OUTPUT_DIR = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Functions for repeating project info

-- Include all src files in the project
function srcFiles()
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
end

-- Set the target and object directories
function setDirs()
	targetdir ("bin/" .. OUTPUT_DIR .. "/%{prj.name}")
	objdir ("bin-int/" .. OUTPUT_DIR .. "/%{prj.name}")
end

-- Projects
project "Horizon"
	location "Horizon"
	kind "StaticLib"
	staticruntime "on"
	cppdialect "C++17"

	pchheader "hrzpch.h"
	pchsource "Horizon/src/hrzpch.cpp"

	setDirs()
	srcFiles()

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/libs/spdlog/include",
	}

	filter "system:windows"
		systemversion "latest"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	staticruntime "on"
	cppdialect "C++17"

	setDirs()
	srcFiles()

	includedirs
	{
		"Horizon/libs/spdlog/include",
		"Horizon/src",
		"Horizon/libs"
	}

	links
	{
		"Horizon"
	}

	filter "system:windows"
		systemversion "latest"