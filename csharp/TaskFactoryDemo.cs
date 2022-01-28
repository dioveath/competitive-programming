using System.IO;
using System;
using System.Threading;
using System.Threading.Tasks;



class TaskFactoryDemo {


    public static void Main(){
        Task[] tasks = new Task[2];
        String[] files = null;
        String[] dirs = null;
        String docDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);

        tasks[0] = Task.Factory.StartNew(() => files = Directory.GetFiles(docDirectory));
        tasks[1] = Task.Factory.StartNew(() => dirs = Directory.GetDirectories(docDirectory));

	Task.Factory.ContinueWhenAll(tasks, completedTasks =>
        {
            Console.WriteLine("{0} contains", docDirectory);
            Console.WriteLine("{0} subdirectories ", dirs.Length);
            Console.WriteLine("{0} files ", files.Length);	    	    
        });

        Thread.Sleep(1000);

    }


}
