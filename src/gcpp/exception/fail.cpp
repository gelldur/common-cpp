//
// Created by Dawid Drozd aka Gelldur on 6/30/16.
//
#include "fail.hpp"

#include <stdexcept>

namespace gcpp::exception
{

std::string trimFromSrcFolder(const std::string_view where)
{
	constexpr std::string_view srcPart{"src/"};
	const auto srcPosition = where.rfind(srcPart);
	if(srcPosition != std::string::npos)
	{
		return std::string{where.substr(srcPosition + srcPart.length())};
	}
	return std::string{where};
}

void fail_if_false(const bool valueToCheck,
				   const std::string_view where,
				   const std::string_view description)
{
	if(valueToCheck == false)
	{
		std::string message = "Fail at: " + trimFromSrcFolder(where);
		if(not description.empty())
		{
			message += ". " + std::string{description};
		}
		throw std::runtime_error{message};
	}
	// All ok!
}

void fail_if_true(const bool valueToCheck,
				  const std::string_view where,
				  const std::string_view description)
{
	if(valueToCheck)
	{
		std::string message = "Fail at: " + trimFromSrcFolder(where);
		if(not description.empty())
		{
			message += ". " + std::string{description};
		}
		throw std::runtime_error{message};
	}
	// All ok!
}

void fail_if_null(const void* pointer,
				  const std::string_view where,
				  const std::string_view description)
{
	if(pointer == nullptr)
	{
		std::string message = "Fail at: " + trimFromSrcFolder(where);
		if(not description.empty())
		{
			message += ". " + std::string{description};
		}
		throw std::runtime_error{message};
	}
	// All ok!
}

void fail_here(const std::string_view where, const std::string_view description)
{
	std::string message = "Fail at: " + trimFromSrcFolder(where);
	if(not description.empty())
	{
		message += ". " + std::string{description};
	}
	throw std::runtime_error{message};
}

} // namespace gcpp::exception
