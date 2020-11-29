all: cmake

cmake : DebugDirectory
	cmake -S . -B Debug ; cd Debug ; make ; ./proj
DebugDirectory:
	mkdir -p Debug 

clean:
	@rm -rf Debug
