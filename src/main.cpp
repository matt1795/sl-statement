// Test program
//
// Author: Matthew Knight
// File Name: main.cpp
// Date: 2018-11-11

#include "../inc/sql-statement.hpp"

#include <iostream>
#include <string>

int main() {
	std::string str = "string";
	sql::Statement sql1, sql2, sql3, sql4;
	sql1
		.select("col1", "col2", str)
		.from("hello", "table")
		.where(
			sql::equal("col", sql::esc("hol")),
			sql::AND,
			sql::notEqual("col2", sql::esc("val"))	
		);

	sql2
		.insertInto("table", "col3", "col4")
		.values(5, "str");
	
	sql3
		.update("table_name")
		.set(sql::equal("col5", "str"), sql::equal("col3", "string"))
		.where(sql::equal("id", "5"));
	
	sql4
		.deleteFrom("some_table")
		.where(sql::greaterThan("column", "4"));
	
	std::cout 
		<< sql1.str() << std::endl
		<< sql2.str() << std::endl
		<< sql3.str() << std::endl
		<< sql4.str() << std::endl;
}
