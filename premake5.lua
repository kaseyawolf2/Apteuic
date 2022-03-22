workspace "Apteuic"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Apteuic"
	location "Apteuic"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines {
			"APTU_PLATFORM_WINDOWS",
			"APTU_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "APTU_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "APTU_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "APTU_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Apteuic/vendor/spdlog/include",
		"Apteuic/src"
	}

	links {
		"Apteuic"
	}

	filter "system:windows"
	cppdialect "C++17"
	staticruntime "On"
	systemversion "10.0.19041.0"

	defines {
		"APTU_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "APTU_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "APTU_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "APTU_DIST"
		optimize "On"
