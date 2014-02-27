<?php 
?>

<!DOCTYPE html 
      PUBLIC "-//W3C//DTD HTML 4.01//EN"
      "http://www.w3.org/TR/html4/strict.dtd">
<html>
<head>

<link href='http://fonts.googleapis.com/css?family=New+Rocker' rel='stylesheet' type='text/css'>
<script>
function validateform1()
{
        var x=document.forms["form1"]['statement'].value;
        if(x==null ||  x=="")
        {
                alert("You've Missed Something :p !");
                return false;
        }
}
</script>

 <link rel="icon" href="./favicon.ico" type="image/x-icon">

<title>


FontMash
</title>

<style>


input#gobutton{
cursor:pointer; /*forces the cursor to change to a hand when the button is hovered*/
padding:5px 25px; /*add some padding to the inside of the button*/
background:#35b128; /*the colour of the button*/
border:1px solid #33842a; /*required or the default border for the browser will appear*/
/*give the button curved corners, alter the size as required*/
-moz-border-radius: 10px;
-webkit-border-radius: 10px;
border-radius: 10px;
/*give the button a drop shadow*/
-webkit-box-shadow: 0 0 4px rgba(0,0,0, .75);
-moz-box-shadow: 0 0 4px rgba(0,0,0, .75);
box-shadow: 0 0 4px rgba(0,0,0, .75);
/*style the text*/
color:#f3f3f3;
font-size:1.1em;
}

input#gobutton:hover, input#gobutton:focus{
background-color :#399630; 
-webkit-box-shadow: 0 0 1px rgba(0,0,0, .75);
-moz-box-shadow: 0 0 1px rgba(0,0,0, .75);
box-shadow: 0 0 1px rgba(0,0,0, .75);
}


body
{
background-image:url(bg.jpg);
}

#rel_go
{
position:relative;
top : 150px;
}
#rel_position
{
position:relative;
top : 100px;
}

#rel_bottom
{
position:relative;
top:200px;
left : 1050px;
}


#table_row
{
position:relative;
top : 20px;
}

</style>

</head>

<body>
<!-- HEADING -->
<div>
<br>
<br>
<br>
<br>
<h1 style="font-family: 'New Rocker', cursive;"  align="center" style="position:relative; top:100px;">

FONT-MASH 
</h1>
</div>

<!-- Body -->
<div>

<form  action="login.php"  name="form1"  onsubmit="return validateform1()"   method="POST">
<table  align="center" border="0" id="rel_position">
<tr>
<td>
Write Your Name  
</td>
</tr>

<tr id="table_row">
<td>
<input type="text" name="statement" value="" ></input> 
</td>
<tr>

</table>

</div>
<div>

<table  align="center" border="0" id="rel_go">
<tr>
<td>
<input type="hidden" name="check1" value="2" ></input> 

<input id="gobutton" type="submit" value="Go!" />

</tr>
</td>

</table>

</form>

</div>

<!-- Footer -->
<div>
</div>

</body>


</html>	
