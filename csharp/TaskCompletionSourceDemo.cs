using System;
using System.Diagnostics;
using System.Threading;
using System.Threading.Tasks;

class TCSDemo {


    static void Main(){

        TaskCompletionSource<int> tcs1 = new TaskCompletionSource<int>();
        Task<int> t1 = tcs1.Task;

        Task.Factory.StartNew(() =>
        {
            Thread.Sleep(1000);
            tcs1.SetResult(92);
        });

        Stopwatch sw = Stopwatch.StartNew();
        int result = t1.Result;
        sw.Stop();

        Console.WriteLine("(ElapsedTime={0}): t1.Result={1} (expected 92)", sw.ElapsedMilliseconds, result);

    }


}
