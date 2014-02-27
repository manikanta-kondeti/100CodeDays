<?php
//header 


//condition checking 
if($_POST['checklogin2']==5)
{
header ('Location:./index.php');
//closing header .
include('values.php');
//ELO RATING ;

$scores[$_POST['file1']]=$scores[$_POST['file1']];
$scores[$_POST['file2']]=$scores[$_POST['file2']]+1;

$expected1=(1/(1+(pow(10,($ratings[$_POST['file2']]-$ratings[$_POST['file1']])/400))));
$expected2=(1/(1+(pow(10,($ratings[$_POST['file1']]-$ratings[$_POST['file2']])/400))));

$ratings[$_POST['file1']]= intval($ratings[$_POST['file1']]+10*($scores[$_POST['file1']]-$expected1));
$ratings[$_POST['file2']]= intval($ratings[$_POST['file2']]+10*($scores[$_POST['file2']]-$expected2));


//End of ELO RATING 




//Writing in a file1 .
$handle1 = fopen('./values/rv'.$_POST['file1'].'.php',"w+");
fwrite($handle1, '<?php');
fwrite($handle1, "\n");
fwrite($handle1, '$ratings['.$_POST['file1'].']=');
fwrite($handle1,$ratings[$_POST['file1']]);  
fwrite($handle1, ";");
fwrite($handle1, "\n");
fwrite($handle1, '$scores['.$_POST['file1'].']=');
fwrite($handle1,$scores[$_POST['file1']]);  
fwrite($handle1, ";");
fwrite($handle1, "\n");
fwrite($handle1, '?>');
fclose($handle1);
//closing the file .

//Writing in a file1 .
$handle2 = fopen('./values/rv'.$_POST['file2'].'.php',"w+");
fwrite($handle2, '<?php');
fwrite($handle2, "\n");
fwrite($handle2, '$ratings['.$_POST['file2'].']=');
fwrite($handle2,$ratings[$_POST['file2']]);  
fwrite($handle2, ";");
fwrite($handle2, "\n");
fwrite($handle2, '$scores['.$_POST['file2'].']=');
fwrite($handle2,$scores[$_POST['file2']]);  
fwrite($handle2, ";");
fwrite($handle2, "\n");
fwrite($handle2, '?>');
fclose($handle2);
//closing the file .


exit;
}
else
{
header ('Location:./welcome.php');
}
?>

