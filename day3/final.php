
<?php 
if($_POST['final']==9)
{

?>
<html>
<head>
 <link rel="icon" href="./favicon.ico" type="image/x-icon">
<title>
FontMash
</title>

<script>
function validateform1()
{
        var x=document.forms["form1"]['suggestion'].value;
        if(x==null ||  x=="")
        {
                alert(" Missed something ?");
                return false;
        }
}
</script>
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
background-image:url('bg.jpg');
}

#rel_position
{
position:relative;
top:200px;
}


</style>


</head>	
<body>
<table align="center" id="rel_position" border="0">
<tr>
<td>
<h4>
Thanks for Visiting !!!  
</h4>
<p>If you are interested go and read EloRating Algorithm. Try to implement it and get the feel. :)</p>
</td>
</tr>

</table>
<!--<input style="position:relative;  left:550px; top:250px;"  id="gobutton" type="submit" value="Submit!" />-->
</form>

</body>
</html>
<?php 
}
else
{
header('Location:./welcome.php');
}
?>
