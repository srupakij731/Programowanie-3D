using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Microsoft.EntityFrameworkCore;

namespace ClassLibrary.Models;

[Table("answers")]
[Index("IdQuestion", Name = "fk_answers_questions")]
public partial class Answer
{
    [Key]
    [Column("id", TypeName = "int(11)")]
    public int Id { get; set; }

    [Column("text", TypeName = "text")]
    public string Text { get; set; } = null!;

    [Column("is_correct")]
    public bool IsCorrect { get; set; }

    [Column("id_question", TypeName = "int(11)")]
    public int IdQuestion { get; set; }

    [ForeignKey("IdQuestion")]
    [InverseProperty("Answers")]
    public virtual Question IdQuestionNavigation { get; set; } = null!;
}
