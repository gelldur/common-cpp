//
// Created by Dawid Drozd aka Gelldur on 10/1/17.
//

#pragma once

#include <functional>

namespace gcpp::guard
{

/**
 * Also checkout std::lock_guard
 * http://en.cppreference.com/w/cpp/thread/lock_guard
 *
 * Read about scope guard idiom
 * https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Scope_Guard
 *
 * C++ standard
 *
 * * 3.7.2/3
 * If a named automatic object has initialization or a destructor with side effects, it shall not be
 * destroyed before the end of its block, nor shall it be eliminated as an optimization even if it
 * appears to be unused
 *
 *
 * https://stackoverflow.com/questions/2087600/is-a-c-destructor-guaranteed-not-to-be-called-until-the-end-of-the-block
 */

class CallOnEnd
{
public:
	explicit CallOnEnd(std::function<void()> onDie) noexcept
		: _onDie(std::move(onDie))
	{}
	explicit CallOnEnd() noexcept = default;

	CallOnEnd(const CallOnEnd&) = delete;
	CallOnEnd(CallOnEnd&& other)
		: _onDie{std::move(other._onDie)}
	{}

	CallOnEnd& operator=(const CallOnEnd&) = delete;
	CallOnEnd& operator=(CallOnEnd&&) = delete;

	~CallOnEnd()
	{
		if(_onDie)
		{
			_onDie();
		}
	}

private:
	std::function<void()> _onDie;
};

} // namespace gcpp::guard
