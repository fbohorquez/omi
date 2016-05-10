#!/usr/bin/perl
sub do_cmd_today{
   local($_) = @_;
   local($sec,$min,$hr,$day,$month,$year) = localtime(time);
   $year = $year;
   $month++;
   $year . $_;
}

sub do_env_framed{
   local($_) = @_;
   "<DIV class=\"requisite\">" . $_ . "</DIV>";
}
1;
