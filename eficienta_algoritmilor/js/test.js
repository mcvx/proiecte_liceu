function fillWithQuestion(nr, q)
{
    $(".item h2.question").html(q[nr].question);
    $(".item .details").html(q[nr].details);
    $(".item .answers").html("");
    $.each(q[nr].answers, function(i, a) {
        $(".item .answers").append("<span class=\"available\"><input type=\"hidden\" name=\"answer\" value=\"" + (i + 1) + "\" />" + a + "</span>");
    });
    $(".item .stats").html((nr + 1) + "/" + q.length);
    $(".item .msg").html("");
}

$(document).ready(function() {
        
    var questions = [], currQ = 0, trueNr = 0, qNr = 0;
    
    $.getJSON("content/intrebari.json", function(data) {
        questions = data;
        fillWithQuestion(0, data);
        qNr = data.length;
    });
    
    $(".item .answers").on("click", "span.available", function() {
        $(".selected").removeClass("selected");
        $(this).addClass("selected");
    });
    
    $("#check").on("click", function(e) {
        e.preventDefault();
        if ($(".selected").size() == 1) {
            $(this).hide();
            if (currQ + 1 < qNr)
                $("#next").show();
            else
                $("#finish").show();
            $(".item .answers span").removeClass("available");
            var trueAnswer = questions[currQ].theanswer;
            var selectedAnswer = $("span.selected input[type=hidden]").val();
            if (selectedAnswer == trueAnswer) {
                trueNr++;
                $(".item .selected").removeClass("selected").addClass("true");
                $(".item .msg").html("<span class=\"true\">Raspuns corect!</span>");
            }
            else {
                $(".item .selected").removeClass("selected").addClass("false");
                $(".item .answers span input[value=" + trueAnswer + "]").parent().addClass("true");
                $(".item .msg").html("<span class=\"false\">Raspuns gresit!</span>");
            }
        }
        else
            $(".item .msg").html("<span class=\"warning\">Nu ai selectat niciun raspuns!</span>");
    });
    
    $("#next").on("click", function(e) {
        e.preventDefault();
        if (currQ + 1 < qNr) {
            $(this).hide();
            $("#check").show();
            currQ++;
            fillWithQuestion(currQ, questions);
        }
    });
    
    $("#finish").on("click", function(e) {
        e.preventDefault();
        $("form.item").remove();
        $("#rezultat").html("Ai raspuns corect la " + trueNr + " din " + qNr + " întrebări!");
        $("#rezultat").show();
    });
    
});
