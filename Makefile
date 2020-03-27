TARGET=AVM
BUILD_DIR=build
SOURCE_DIR=$(PWD)

all:
	cmake -B$(BUILD_DIR)
	cmake --build $(BUILD_DIR)
	cp $(BUILD_DIR)/$(TARGET) .


$(TARGET) : $(BUILD_DIR)/$(TARGET)
	cp $(BUILD_DIR)/$(TARGET) .

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(TARGET)

re : fclean all

