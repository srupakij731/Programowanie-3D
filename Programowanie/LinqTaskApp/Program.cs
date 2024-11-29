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
var task7 = tasks.OrderBy(t => t.IsCompleted).ThenBy(t => t.Name).GroupBy(t => t.IsCompleted);
var task8 = tasks.Where(t => !t.IsCompleted).OrderBy(t => t.Name.Length).First();
var task9 = tasks.Where(t => t.IsCompleted).Select(t => t.Name.Length).Sum();
var task10 = tasks.Where(t => t.IsCompleted).Select((t, index) => new { Index = index + 1, T = t });
var task11 = tasks.GroupBy(t => t.IsCompleted)
    .Select(g => new { GroupVaule = g.Key, MaxName = g.OrderByDescending(t => t.Name.Length).First().Name });
var task12 = tasks.GroupBy(t => t.IsCompleted).Select(g=> new {GroupName = g.Key, Count = g.Where(p => p.Name.Contains("the")).Count()});
var task13 = tasks.Where(t => t.IsCompleted).Select((g,Index) => new { length = g.Name.Length, index = Index+1 });
var task14 = tasks.OrderBy(t => t.IsCompleted).ThenBy(t => t.Name);
var task15 = tasks.All(t => t.Name.ToLower().Where(c => "aeiouy".Contains(c)).Distinct().Count() >= 2);
var task16 = tasks.Where(t => t.IsCompleted).SelectMany(t => t.Name.Where(c=> char.IsLetter(c)).Distinct());