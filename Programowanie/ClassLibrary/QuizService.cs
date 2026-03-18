using ClassLibrary.Models;
using Microsoft.EntityFrameworkCore;

namespace ClassLibrary
{
    public class QuizService
    {
        private QuizDBContext db = new QuizDBContext(); 
        public Question GetQuestion(int id)
        {
            return db.Questions.FirstOrDefault(q => q.Id == id);
        }
        public List<Answer> GetAnswers(int id)
        {
            return db.Answers.Where(a => a.IdQuestion == id).ToList();
        }
    }
}
