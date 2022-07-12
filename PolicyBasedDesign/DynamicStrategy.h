#pragma once

#include <string>
#include <iostream>


/////////////////////////////////////////////////////////////////////////// Strategies

struct ILoggingStrategy
{
	virtual void log(const std::string& message) = 0;
};


struct StarLoggingStrategy : ILoggingStrategy
{
	void log(const std::string& message) override
	{
		std::cout << "*** " << message << " ***\n";
	}
};

struct ErrorLoggingStrategy : ILoggingStrategy
{
	void log(const std::string& message) override
	{
		std::cout << "Error: " << message << std::endl;
	}
};

struct NoLoggingStrategy : ILoggingStrategy // empty object pattern
{
	void log(const std::string& message) override
	{
		// empty
	}
};




/////////////////////////////////////////////////////////////////////////// Context

struct DynamicStrategyApplication
{
	ILoggingStrategy* logging_;

	void setLogging(ILoggingStrategy* logging)
	{
		logging_ = logging;
	}

	void run()
	{
		logging_->log("Application start running");
	}

	void shutdown()
	{
		logging_->log("Application shutdown");
	}
};




/////////////////////////////////////////////////////////////////////////// Example

void dynamicStrategyExample()
{
	std::cout << "===> Dynamic Strategy example:\n\n";

	DynamicStrategyApplication application;

	ILoggingStrategy* starLogging = new StarLoggingStrategy();
	application.setLogging(starLogging);
	application.run();
	// some logic here
	application.shutdown();

	ILoggingStrategy* errorLogging = new ErrorLoggingStrategy();
	application.setLogging(errorLogging);
	application.run();
	// some logic here
	application.shutdown();


	ILoggingStrategy* noLogging = new NoLoggingStrategy();
	application.setLogging(noLogging);
	application.run();
	// some logic here
	application.shutdown();


	// yes, we need to delete allocated memory

	std::cout << "\n\n\n";
}
