
namespace App1
{
    public static class Program
    {
        [System.Runtime.InteropServices.DllImport("api-ms-win-core-processthreads-l1-1-0.dll")]
        private static extern void ExitProcess(int code);
        public static void Main(string[] args)
        {
            System.Console.WriteLine(@"English
中文 (简体)
中文 (繁體)
한국어
😀😁😂🤣
");
            ExitProcess(0);
        }
    }
}