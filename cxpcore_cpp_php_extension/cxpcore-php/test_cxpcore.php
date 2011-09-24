<?php

$module = 'php_cxpcore';
if(!extension_loaded('$module')) {
  dl("$module.dll");
}

$functions = get_extension_funcs($module);
$out = '';
$out .= "Functions available in the test extension:\n";
foreach($functions as $func) {
    $out .= $func."\n";
}
$out .= "\n";
$function = 'confirm_' . $module . '_compiled';
if (extension_loaded($module)) {
	$str = $function($module);
} else {
	$str = "Module $module is not compiled into PHP";
}
$out .= "$str\n";

$out .= cxpcore_test("test this string");
echo nl2br($out);
?>
