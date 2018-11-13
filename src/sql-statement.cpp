// SQL Statement Class
//
// Author: Matthew Knight
// File Name: sql-statement.cpp
// Date: 2018-11-11
//
// This class and functions help construct SQL Statements

#include "../inc/sql-statement.hpp"

#include <iostream>
#include <string>
#include <sstream>

namespace sql {	
	// comparison functions
	std::string comparison(
		const std::string& col, 
		const std::string& op, 
		const std::string& val
	) {
		return col + op + val;
		
	}
	
	std::string equal(const std::string& col, const std::string& val) {
		return comparison(col, "=", val);
	}

	std::string notEqual(const std::string& col, const std::string& val) {
		return comparison(col, "<>", val);
	}

	std::string lessThan(const std::string& col, const std::string& val) {
		return comparison(col, "<", val);

	}

	std::string greaterThan(const std::string& col, const std::string& val) {
		return comparison(col, ">", val);

	}

	std::string lessThanOrEqual(
		const std::string& col, 
		const std::string& val
	) {
		return comparison(col, "<=", val);
	}

	std::string greaterThanOrEqual(
		const std::string& col, 
		const std::string& val
	) {
		return comparison(col, ">=", val);
	}

	std::string esc(const std::string& str) {
		return "'" + str + "'";
	}
};
