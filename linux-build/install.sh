echo "Installing ticket-recognition-jcpp"
myRepo="$(pwd)/.."
CMAKE_CONFIG_GENERATOR="Unix Makefiles"

cmake -G"$CMAKE_CONFIG_GENERATOR" -DCMAKE_INSTALL_PREFIX="$myRepo"/build -DPROJECT_BINARY_DIR="$myRepo"/build -DLINUX_BUILD=true -DCMAKE_PROJECT_NAME="ticket_recognition_jcpp" "$myRepo/sources"
echo "************************* $Source_DIR -->debug"
cmake --build .  --config release
cmake --build .  --target ticket_recognition_jcpp --config release