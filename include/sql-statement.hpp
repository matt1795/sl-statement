// SQL Statement Class
//
// Author: Matthew Knight
// File Name: sql-statement.hpp
// Date: 2018-11-11
//
// This class and functions help construct SQL Statements

#include <iostream>
#include <string>
#include <sstream>

namespace sql {
	// constants
	const std::string AND = "AND";
	const std::string OR = "OR";
	const std::string NOT = "NOT";
	const std::string ALL = "*";
	const std::string BETWEEN = "BETWEEN";
	const std::string LIKE = "LIKE";
	const std::string IN = "IN";
	const std::string ASC = "ASC";
	const std::string DESC = "DESC";

	std::string esc(const std::string& str);

	// comparison operators
	std::string equal(const std::string& col, const std::string& val);
	std::string notEqual(const std::string& col, const std::string& val);
	std::string lessThan(const std::string& col, const std::string& val);
	std::string greaterThan(const std::string& col, const std::string& val);
	std::string lessThanOrEqual(const std::string& col, const std::string& val);
	std::string greaterThanOrEqual(const std::string& col,
		const std::string& val);

	// statement class
	class Statement {
		std::stringstream buf;

		// comma separated list
		template <class T>
		void comma(const T& val) {
			buf << val;
		}

		// comma separeted list -- recursive
		template <class T, class ... Args>
		void comma(const T& val, Args ... args) {
			buf << val << ",";
			comma(args...);
		}

		// comma separated list
		template <class T>
		void space(const T& val) {
			buf << val;
		}

		// comma separeted list -- recursive
		template <class T, class ... Args>
		void space(const T& val, Args ... args) {
			buf << val << " ";
			space(args...);
		}

	public:

		// insert select statement with columns
		template <class ... Args>
		Statement& select(Args ... args) {
			buf << "SELECT ";
			comma(args...);
			buf << std::endl;
			return *this;
		}

		// insert from statement
		template <class ... Args>
		Statement& from(Args ... args) {
			buf << "FROM ";
			comma(args...);
			buf << std::endl;
			return *this;
		}

		// insert where statement
		template <class ... Args>
		Statement& where(Args ... args) {
			buf << "WHERE ";
			space(args...);
			buf << std::endl;
			return *this;
		}

		// insert INSERT statement
		template <class ... Args>
		Statement& insertInto(const std::string& table, Args ... args) {
			buf
				<< "INSERT INTO "
				<< table << " (";

			comma(args...);
			buf << ") ";

			buf << std::endl;
			return *this;
		}

		// insert Values statement
		template <class ... Args>
		Statement& values(Args ... args) {
			buf << "VALUES (";
			comma(args...);
			buf << ")" << std::endl;
			return *this;
		}

		// insert delete from statement
		Statement& deleteFrom(const std::string& table) {
			buf << "DELETE FROM " << table << std::endl;
			return *this;
		}

		// insert update statement
		Statement& update(const std::string& table) {
			buf << "UPDATE " << table << std::endl;
			return *this;
		}

		// insert set statement
		template <class ... Args>
		Statement& set(Args ... args) {
			buf << "SET ";
			space(args...);
			buf << std::endl;
			return *this;
		}

		// inner join statement
		template <class T>
		Statement& innerJoin(const T& table) {
			buf << "INNER JOIN " << table << std::endl;
			return *this;
		}

		// on statement
		template <class T>
		Statement& on(const T& bind) {
			buf << "ON " << bind << std::endl;
			return *this;
		}

		template <typename ... Args>
		Statement& orderBy(Args ... args) {
			buf << "ORDER BY ";
			comma(args...);
			buf << std::endl;
			return *this;
		}

		std::string str() {
			return buf.str();
		}
	};
};
