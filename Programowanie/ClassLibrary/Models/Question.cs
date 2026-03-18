using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Microsoft.EntityFrameworkCore;

namespace ClassLibrary.Models;

[Table("questions")]
public partial class Question
{
    [Key]
    [Column("id", TypeName = "int(11)")]
    public int Id { get; set; }

    [Column("text", TypeName = "text")]
    public string Text { get; set; } = null!;

    [InverseProperty("IdQuestionNavigation")]
    public virtual ICollection<Answer> Answers { get; set; } = new List<Answer>();
}
