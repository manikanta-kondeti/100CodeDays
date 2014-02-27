<?php

//condition checking 


// writing statement in a file 

$handle3 = fopen('./suggestions.php',"a+");
fwrite($handle3, '<?php');
fwrite($handle3, "\n");
fwrite($handle3, '$_POST[');
fwrite($handle3, "'");
fwrite($handle3, "suggestion");
fwrite($handle3, "'");
fwrite($handle3, "]");
fwrite($handle3, '='.'"'.$_POST['suggestion']);
fwrite($handle3, '";');
fwrite($handle3, "\n");
fwrite($handle3, '?>');
fclose($handle3);

//end of writing statement :



//header 
header ('Location:./welcome.php');
//closing header .
exit;
?>

