#pragma once


#include <string>
#include <iostream>
#include <type_traits>


/////////////////////////////////////////////////////////////////////////// Policies/Strategies

struct StarLoggingPolicy
{
	void log(const std::string& message)
	{
		std::cout << "*** " << message << " ***\n";
	}
};

struct ErrorLoggingPolicy
{
	void log(const std::string& message)
	{
		std::cout << "Error: " << message << std::endl;
	}
};

struct NoLoggingPolicy
{
	void log(const std::string& message)
	{
		// empty
	}
};


/////////////////////////////////////////////////////////////////////////// Context

template <typename LoggingPolicy>
struct StaticStrategyApplication
{
	LoggingPolicy logging_;

	void run()
	{
		logging_.log("Application start running"); // duck typing
	}

	void shutdown()
	{
		logging_.log("Application shutdown"); // duck typing
	}
};


/////////////////////////////////////////////////////////////////////////// Example

void staticStrategyExample()
{
	std::cout << "===> Static strategy example:\n\n";

	StaticStrategyApplication<StarLoggingPolicy> applicationWithStarLogging;
	applicationWithStarLogging.run();
	// some logic here
	applicationWithStarLogging.shutdown();


	StaticStrategyApplication<ErrorLoggingPolicy> applicationWithErrorLogging;
	applicationWithErrorLogging.run();
	// some logic here
	applicationWithErrorLogging.shutdown();


	StaticStrategyApplication<NoLoggingPolicy> applicationWithNoLogging;
	applicationWithNoLogging.run();
	// some logic here
	applicationWithNoLogging.shutdown();

	std::cout << "\n\n\n";
}



/////////////////////////////////////////////////////////////////////////// Better Example

// Better policy based application
template <typename T>
using has_log_method = std::is_void<decltype(std::declval<T>().log(std::declval<std::string>()))>;

template <typename LoggingPolicy>
struct BetterStaticStrategyApplication
{
	static_assert(has_log_method<LoggingPolicy>::value, "Policy has no 'void log(std::string)' method");

	LoggingPolicy logging_;

	void run()
	{
		logging_.log("Application start running");
	}

	void shutdown()
	{
		logging_.log("Application shutdown");
	}
};


// Some dummy class
struct Duck
{
	void quack()
	{
		std::cout << "quack :|\n";
	}
};


void betterStaticStrategyExample()
{
	std::cout << "===> Better static strategy example:\n\n";

	BetterStaticStrategyApplication<StarLoggingPolicy> applicationWithStarLogging;
	applicationWithStarLogging.run();
	applicationWithStarLogging.shutdown();

	//BetterStaticStrategyApplication<Duck> applicationWithDuck;
	//applicationWithDuck.run();
	//applicationWithDuck.shutdown();


	std::cout << "\n\n\n";
}