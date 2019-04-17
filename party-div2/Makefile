PACKAGE_DIR = package
BUILD_DIR = build
SOURCE_DIR = src

CXX = g++
CXXFLAGS += -std=c++11 -g -O2 -Wall -pipe -I./include

CP = cp

SRCS = $(shell find $(SOURCE_DIR) -name "*.cpp")
OBJS = $(SRCS:$(SOURCE_DIR)/%.cpp=$(BUILD_DIR)/%)

.PHONY : default clean datagen kattis cf

default : datagen

# generate c++ executables
$(BUILD_DIR)/% : $(SOURCE_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo + [C++]\\t\\t$@
	@$(CXX) $(CXXFLAGS) -o $@ $<

# copy python scripts
$(BUILD_DIR)/%.py : $(SOURCE_DIR)/%.py
	@mkdir -p $(dir $@)
	@echo + [CP]\\t\\t$@
	@$(CP) $< $@
	@chmod +x $@

# generate answer file
%.ans : %.in $(BUILD_DIR)/std
	@mkdir -p $(dir $@)
	@echo + [GEN]\\t\\t$@
	@$(BUILD_DIR)/std < $< > $@

%.desc : %.in $(BUILD_DIR)/std
	@mkdir -p $(dir $@)
	@echo + [GEN]\\t\\t$@
	@$(BUILD_DIR)/std < $< 2> $@

%.png : $(BUILD_DIR)/plot.py %.desc %.in
	@mkdir -p $(dir $@)
	@echo + [GEN]\\t\\t$@
	@$(BUILD_DIR)/plot.py $(word 2, $^) $@ < $(word 3, $^)
	
clean :
	rm -rf $(BUILD_DIR)
	rm -rf $(PACKAGE_DIR)
	rm -rf Makefile.data package.zip

Makefile.data : datamake.py data.yaml
	./datamake.py > Makefile.data

-include Makefile.data

datagen: $(DATA_TARGETS)
.DELETE_ON_ERROR : $(DATA_TARGETS)

kattis: datagen
	mkdir -p $(PACKAGE_DIR)/data/sample
	mkdir -p $(PACKAGE_DIR)/data/secret
	cp problem.yaml  $(PACKAGE_DIR)/problem.yaml
	mv $(PACKAGE_DIR)/data/*sample*.* $(PACKAGE_DIR)/data/sample
	mv $(PACKAGE_DIR)/data/*.* $(PACKAGE_DIR)/data/secret
	cd $(PACKAGE_DIR) && zip -r ../package.zip .

