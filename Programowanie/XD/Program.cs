using System;
using System.ComponentModel;
using System.Xml.Linq;
using System.Timers;
using static System.Runtime.InteropServices.JavaScript.JSType;
class Program
{
    const int boardSize = 9;
    static string currentDirection = "right";
    static GameObject[,] board = new GameObject[boardSize, boardSize];
    static Snake snake = new Snake();
    static System.Timers.Timer timer = new System.Timers.Timer(200);



    class GameObject
    {
        public GameObject(int y, int x)
        {
            this.y = y;
            this.x = x;
        }
        public GameObject()
        {
        }
        public void Interaction()
        {
        }
        protected int x;
        public int X
        {
            get { return x; }
            set { x = value; }
        }
        protected int y;
        public int Y
        {
            get { return y; }
            set { y = value; }
        }
        private char sign = '.';
        public char Sign
        {
            get { return sign; }
            set { sign = value; }
        }
    }

    class SnakePart : GameObject
    {
        public SnakePart(int Y, int X) : base(Y, X)
        {
            Sign = 'S';
        }
    }

    class Snake : GameObject
    {
        protected SnakePart[] snake;

        public Snake()
        {
            snake = new SnakePart[2];
            snake[0] = new SnakePart(3, 4);
            snake[1] = new SnakePart(3, 3);

            snake[0].Sign = 'H';
        }

        public void Move(string direction)
        {


            for (int i = snake.Length - 1; i > 0; i--)
            {
                snake[i].X = snake[i - 1].X;
                snake[i].Y = snake[i - 1].Y;

            }
            switch (direction)
            {
                case "right":
                    snake[0].X += 1;
                    break;
                case "left":
                    snake[0].X -= 1;
                    break;
                case "up":
                    snake[0].Y -= 1;
                    break;
                case "down":
                    snake[0].Y += 1;
                    break;
            }

        }
        public void ChangeDirection(string newDirection)
        {
            if ((currentDirection == "right" && newDirection != "left") ||
                (currentDirection == "left" && newDirection != "right") ||
                (currentDirection == "up" && newDirection != "down") ||
                (currentDirection == "down" && newDirection != "up"))
            {
                currentDirection = newDirection;
            }
        }
        public SnakePart[] GetSnakeParts()
        {
            return snake;
        }
    }

    static void drawBoard()
    {
        Console.Clear();
        for (int i = 0; i < boardSize; i++)
        {
            for (int j = 0; j < boardSize; j++)
            {
                Console.Write(board[i, j].Sign);
            }
            Console.Write("\n");
        }
    }
    static void removeSnake()
    {

        foreach (SnakePart part in snake.GetSnakeParts())
        {
            board[part.Y, part.X] = new GameObject(part.Y, part.X);
        }
    }
    static void addSnake()
    {

        foreach (SnakePart part in snake.GetSnakeParts())
        {
            board[part.Y, part.X] = part;
        }
    }

    static void moveSnake(object sender, ElapsedEventArgs e)
    {
        removeSnake();
        snake.Move(currentDirection);
        addSnake();
        drawBoard();
    }

    static void Main(string[] args)
    {
        for (int i = 0; i < boardSize; i++)
        {
            for (int j = 0; j < boardSize; j++)
            {
                board[i, j] = new GameObject(i, j);
            }
        }
        addSnake();
        drawBoard();
        timer.Elapsed += moveSnake;
        timer.Start();

            while (true)
            {
                var keyInfo = Console.ReadKey(intercept: true);
                if (keyInfo.Key == ConsoleKey.LeftArrow)
                    snake.ChangeDirection("left");
                else if (keyInfo.Key == ConsoleKey.RightArrow)
                    snake.ChangeDirection("right");
                else if (keyInfo.Key == ConsoleKey.UpArrow)
                    snake.ChangeDirection("up");
                else if (keyInfo.Key == ConsoleKey.DownArrow)
                    snake.ChangeDirection("down");
            }

    }
}