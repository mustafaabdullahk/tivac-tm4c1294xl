# invoke SourceDir generated makefile for uart_test_code.pem4f
uart_test_code.pem4f: .libraries,uart_test_code.pem4f
.libraries,uart_test_code.pem4f: package/cfg/uart_test_code_pem4f.xdl
	$(MAKE) -f C:\Users\PACKAR~1\workspace_v9\uart_test_code/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\PACKAR~1\workspace_v9\uart_test_code/src/makefile.libs clean

