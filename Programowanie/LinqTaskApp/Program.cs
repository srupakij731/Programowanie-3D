using LinqTasksConsoleApp;

var tasks = new List<TaskItem>
{
    new TaskItem(1, "Buy groceries", true),
    new TaskItem(2, "Clean the house", false),
    new TaskItem(3, "Pay bills", true),
    new TaskItem(4, "Study LINQ", false),
    new TaskItem(5, "Exercise", true)
};

var task1 = tasks.Where(t => t.IsCompleted).ToList();
TaskItem task2 = tasks.First(t => !t.IsCompleted);
var task3 = tasks.OrderBy(t => t.Name).ToList();
var task4 = tasks.Count(t => t.IsCompleted);
var task5 = tasks.Select(t => t.Name).ToList();

var task6 = tasks.Where(t => t.IsCompleted).Select(t => t.Name).OrderBy(t => t).ToList();
//var task7 = tasks.GroupBy(t => t.IsCompleted);
var task8 = tasks.Where(t => !t.IsCompleted).OrderBy(t => t.Name.Length).First();
var task9 = tasks.Where(t => t.IsCompleted).Select(t => t.Name.Length).ToList();
//var task10 = tasks.Where(t => t.IsCompleted).Select(t => t.Name);

