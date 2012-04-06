.PHONY: clean All

All:
	@echo ----------Building project:[ GitM - Debug ]----------
	@"$(MAKE)" -f "GitM.mk"
clean:
	@echo ----------Cleaning project:[ GitM - Debug ]----------
	@"$(MAKE)" -f "GitM.mk" clean
