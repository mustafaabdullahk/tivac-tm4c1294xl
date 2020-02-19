# invoke SourceDir generated makefile for mutex.pem4f
mutex.pem4f: .libraries,mutex.pem4f
.libraries,mutex.pem4f: package/cfg/mutex_pem4f.xdl
	$(MAKE) -f C:\Users\PACKAR~1\workspace_v9\uart_test_code/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\PACKAR~1\workspace_v9\uart_test_code/src/makefile.libs clean

