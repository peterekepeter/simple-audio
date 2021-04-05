# simple-audio

[![CI](https://github.com/peterekepeter/simple-audio/actions/workflows/main.yml/badge.svg)](https://github.com/peterekepeter/simple-audio/actions/workflows/main.yml)

This project massively simplifies adding audio support to a project. 
The catch? It uses bass.dll for which you need license for commertial usage.

## Usage

The library operates on a "fire and forget" core principle. This means you
don't have much work to do to get it working.

	Music::Init("sine-song.it", false);
	Music::Play();

## Missing bass.dll?

The dll is included in the repo for convenience. In case it doesn't copy to
the output folder I recommend setting up a copy command.

	xcopy "$(SolutionDir)bass24\bass.dll" "$(OutDir)" /Y

For latest version of bass check out their site. https://www.un4seen.com/