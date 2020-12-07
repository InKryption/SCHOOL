.ONESHELL:

# start FUNCTIONS
define All_Files_Inside
$(foreach file,$(wildcard $(1)/*),$(if $(wildcard $(file)/*),$(call All_Files_Inside,$(file)),$(file)))
endef
# end FUNCTIONS

COMPILER:=x86_64-w64-mingw32-g++-posix

# Absolute root to project folder
root:=.

BIN:=bin
SRC:=src
BUILD:=Release
NAME:=login_prog

SRC_FOLDER:=$(root)/$(SRC)# Source folder absolute path
BIN_FOLDER:=$(root)/$(BIN)# Binary folder absolute path

# Linker Flags
LFlags:=\
-static

# Compiler Flags
CFlags:=\
-I$(SRC_FOLDER) \
-std=gnu++17 -O3\

# Output & Object Output directories
ODIR:=$(BIN_FOLDER)/$(BUILD)
OBJDIR:=$(ODIR)/obj

# List of Source file paths, and a list of matching object files
SOURCE_FILES:=$(filter %.cpp,$(call All_Files_Inside,$(SRC_FOLDER)))
OBJECT_FILES:=$(foreach src,$(SOURCE_FILES),$(OBJDIR)/$(firstword $(subst ., ,$(notdir $(src)))).o)

$(ODIR)/$(NAME).exe: $(OBJECT_FILES)
	@echo ""
	$(COMPILER) $(OBJECT_FILES) -o $(ODIR)/$(NAME).exe $(LFlags)
	@echo ""


# Do this in the foreach, so that every source file in the list created before goes through this process automatically.
define Compile_Source
$(OBJDIR)/$(notdir $(firstword $(subst ., ,$(1)))).o: $(1) $(filter %$(notdir $(firstword $(subst ., ,$(1)))).hpp,$(call All_Files_Inside,$(SRC_FOLDER)))
	$(COMPILER) -c $(1) -o $(OBJDIR)/$(notdir $(firstword $(subst ., ,$(1)))).o $(CFlags)
endef
$(foreach src,$(SOURCE_FILES),$(eval $(call Compile_Source,$(src))))

.PHONY: clean dir run

# Run the output
run: $(ODIR)/$(NAME).exe
	-$(ODIR)/$(NAME).exe
	
dir:
ifeq ($(wildcard $(BIN_FOLDER)/*),)
	-mkdir -p $(OBJDIR)
else ifeq ($(wildcard $(ODIR)/*),)
	-mkdir -p  $(OBJDIR)
endif

# Clean all object files that have no equivalent source file
Dirty_Objects=$(foreach pdo,$(wildcard $(OBJDIR)/*),$(if $(filter $(pdo),$(OBJECT_FILES)),,$(pdo)))

clean:
	@rm $(Dirty_Objects)
	@echo $(Dirty_Objects)