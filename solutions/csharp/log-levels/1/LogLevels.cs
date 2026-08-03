static class LogLine
{
    public static string Message(string logLine)
    {
        int start = logLine.IndexOf(' ') + 1;

        return logLine.Substring(start).Trim();
    }

    public static string LogLevel(string logLine)
    {
        int stop = logLine.IndexOf(']');

        return logLine[1..stop].ToLower().Trim();
    }

    public static string Reformat(string logLine)
    {
        return $"{Message(logLine)} ({LogLevel(logLine)})";
    }
}
