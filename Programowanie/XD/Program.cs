using System;
using System.Collections.Generic;
using System.Timers;

class Program
{
    const int boardSize = 9;
    static string currentDirection = "right";
    static Game game = new Game();
    static System.Timers.Timer timer = new System.Timers.Timer(200);

    class GameObject
    {
        public GameObject(int y, int x)
        {
            Y = y;
            X = x;
            Sign = '.';
        }
        public GameObject()
        {
            Sign = '.';
        }
        public virtual void Interaction() { }
        public int X { get; set; }
        public int Y { get; set; }
        public char Sign { get; set; }
    }

    class Apple : GameObject
    {
        public Apple()
        {
            Random r = new Random();
            Y = r.Next(0, boardSize);
            X = r.Next(0, boardSize);
            Sign = '@';
        }
        public override void Interaction()
        {
            game.Snake.AddSnakePart();
            game.AddApple();
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
        private List<SnakePart> snake = new List<SnakePart>();

        public Snake()
        {
            snake.Add(new SnakePart(3, 4));
            snake.Add(new SnakePart(3, 3));
            snake[0].Sign = 'H';
        }

        public void Move()
        {
            for (int i = snake.Count - 1; i > 0; i--)
            {
                snake[i].X = snake[i - 1].X;
                snake[i].Y = snake[i - 1].Y;
            }
            switch (currentDirection)
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
            CheckCollision();
        }

        public void AddSnakePart()
        {
            var tail = snake[snake.Count - 1];
            snake.Add(new SnakePart(tail.Y, tail.X));
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

        public List<SnakePart> GetSnake()
        {
            return snake;
        }

        private void CheckCollision()
        {
            // Check if snake collides with itself or with the walls (not implemented in this basic version)
        }
    }

    class Game
    {
        private GameObject[,] board = new GameObject[boardSize, boardSize];
        public Snake Snake { get; private set; }

        public Game()
        {
            Snake = new Snake();
            InitializeBoard();
            AddSnake();
            AddApple();
        }

        private void InitializeBoard()
        {
            for (int i = 0; i < boardSize; i++)
            {
                for (int j = 0; j < boardSize; j++)
                {
                    board[i, j] = new GameObject(i, j);
                }
            }
        }

        public void AddSnake()
        {
            foreach (SnakePart part in Snake.GetSnake())
            {
                board[part.Y, part.X] = part;
            }
        }

        public void AddApple()
        {
            Apple apple = new Apple();
            board[apple.Y, apple.X] = apple;
        }

        public void DrawBoard()
        {
            Console.Clear();

            for (int i = 0; i < boardSize; i++)
            {
                for (int j = 0; j < boardSize; j++)
                {
                    Console.Write(board[i, j].Sign);
                }
                Console.WriteLine();
            }
        }

        public void RemoveSnake()
        {
            foreach (SnakePart part in Snake.GetSnake())
            {
                board[part.Y, part.X] = new GameObject(part.Y, part.X);
            }
        }

        public void MoveSnake(object sender, ElapsedEventArgs e)
        {
            RemoveSnake();
            Snake.Move();
            List<SnakePart> snakeParts = Snake.GetSnake();
            board[snakeParts[0].Y, snakeParts[0].X].Interaction();
            AddSnake();
            DrawBoard();
        }
    }

    static void Main(string[] args)
    {
        game.DrawBoard();
        timer.Elapsed += game.MoveSnake;
        timer.Start();

        while (true)
        {
            var keyInfo = Console.ReadKey(intercept: true);
            if (keyInfo.Key == ConsoleKey.LeftArrow)
                game.Snake.ChangeDirection("left");
            else if (keyInfo.Key == ConsoleKey.RightArrow)
                game.Snake.ChangeDirection("right");
            else if (keyInfo.Key == ConsoleKey.UpArrow)
                game.Snake.ChangeDirection("up");
            else if (keyInfo.Key == ConsoleKey.DownArrow)
                game.Snake.ChangeDirection("down");
        }
    }
}
