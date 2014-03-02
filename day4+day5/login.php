<?php

//condition checking 
if($_POST['check1']==2)
{
include('values.php');


// writing statement in a file 

$handle3 = fopen('./names.php',"a+");
fwrite($handle3, '<?php');
fwrite($handle3, "\n");
fwrite($handle3, '$_POST[');
fwrite($handle3, "'");
fwrite($handle3, "statement");
fwrite($handle3, "'");
fwrite($handle3, "]");
fwrite($handle3, '='.'"'.$_POST['statement']);
fwrite($handle3, '";');
fwrite($handle3, "\n");
fwrite($handle3, '?>');
fclose($handle3);

//end of writing statement :



//header 
header ('Location:./index.php');
//closing header .
exit;
}
else
{
header ('Location:./welcome.php');
}
?>

