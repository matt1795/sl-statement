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
	sql::Statement statement;
	statement
		.select("col1", "col2", str)
		.from("hello", "table")
		.where(
			sql::equal("col", "hol"),
			sql::AND,
			sql::notEqual("col2", "val")	
		);
	
	std::cout << statement.str() << std::endl;
}
