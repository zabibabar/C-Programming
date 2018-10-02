employeePayroll: employeePayroll.o employee.o linkedList.o
	c99 -o employeePayroll employeePayroll.o employee.o linkedList.o

employeePayroll.o: employeePayroll.c employee.h
	c99 -c employeePayroll.c

employee.o: employee.c employee.h
	c99 -c employee.c

linkedList.o: linkedList.c linkedList.h
	c99 -c linkedList.c