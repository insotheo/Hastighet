using System;

namespace Hastighet.Core
{
    public static class Log
    {

#if DEBUG
        public static bool IsDebugEnabled = true;
#else
        public static bool IsDebugEnabled = false;
#endif

        private static void PrintWithFormating(string message, string sender)
        {
            Console.WriteLine($"[{DateTime.Now.ToString("T")}] {sender}: {message}");
            Console.ResetColor();
        }

        public static void Trace<T>(T message, string sender = "Hastighet")
        {
            if (IsDebugEnabled)
            {
                Console.ResetColor();
                PrintWithFormating(message.ToString(), sender);
            }
        }

        public static void Info<T>(T message, string sender = "Hastighet")
        {
            if (IsDebugEnabled)
            {
                Console.ForegroundColor = ConsoleColor.Green;
                PrintWithFormating(message.ToString(), sender);
            }
        }

        public static void Warn<T>(T message, string sender = "Hastighet")
        {
            if (IsDebugEnabled)
            {
                Console.ForegroundColor = ConsoleColor.Yellow;
                PrintWithFormating(message.ToString(), sender);
            }
        }

        public static void Error<T>(T message, string sender = "Hastighet")
        {
            if (IsDebugEnabled)
            {
                Console.ForegroundColor = ConsoleColor.Red;
                if (message is Exception exception)
                {
                    PrintWithFormating(exception.Message, sender);
                }
                else
                {
                    PrintWithFormating(message.ToString(), sender);
                }
            }
        }

    }
}
