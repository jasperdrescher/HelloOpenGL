echo "Initializing submodules"
git submodule update --init --recursive
mkdir Dependencies
echo "Generating GLFW"
cd Dependencies
mkdir GLFW
cd ..
cmake -DGLFW_USE_HYBRID_HPG=ON -DGLFW_BUILD_TESTS=OFF -DGLFW_BUILD_TESTS=OFF -DGLFW_INSTALL=OFF -DGLFW_BUILD_DOCS=OFF -DGLFW_BUILD_EXAMPLES=OFF -S Submodules/glfw -B Dependencies/GLFW
echo "Building GLFW"
cmake --build Dependencies/GLFW --target glfw --config Debug
echo "Generating GLAD"
cd Dependencies
mkdir GLAD
cd ..
cmake -S Submodules/GLAD -B Dependencies/GLAD
echo "Building GLAD"
cmake --build Dependencies/GLAD --target glad --config Debug