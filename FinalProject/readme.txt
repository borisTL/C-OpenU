/*Mmaman14-readme file*/
/*The project was created by Boris Teplitski
/*The project was created by the instructions of maman14*/
[Pseudocode :]
.f  -function
.c  -file c 
<-> -move to another file
->  -movement in file
* function in file
 [1]		[2]	    [3]
main.c: ->assabler.f  <->assambler.c:->     [4]
					*handleSingel.f:          
						[5]			[6]
					  *initialize_program.f <-> creaData.c:         [7]
										 initialize_program.f
					         	 [8]
					  *      perAssambler.f:<->   [9]
								  perAssambler.c: 
										        [10]		    [11]
								   		    *preAssambler.f -> replace_keys_with_values.f 
						     [12]		[13]
					 *      first_pass.f   <->    firstRun.c:	[14]		    [15]    
										   *parse_line.f      <-> lexer.c:	      [16]
															   *parse_line.f 

							   			          [17]			[18]							
										   *syntax_analiz.f   <-> syntax_analiz.c:     [19]
															    *syntax_analiz.f

											[20]		     [21]			
					         				   *inToSymbolTable.f <-> symbolTab.c:         [22]
															 inTosymbolTable.f
						    [23]	       [24]
					 *      secondRun.f    <->  seconfRun.c:   	[25]		     [26]       
										   *parse_line.f       <-> lexer.c:      [27]
														      *pase_line.f
										          [28]                  [29]
										    *analiz_operand.f    <-> syntax_analiz.c:     [30]
															      *analiz_operand.f
										          [31]				[32]
										    *add_to_mamory_machine_code.f <-> memory.c:        [33]
																add_to_mamory_machine_code.f
										   
									[34]	
				        *       write_entries_to_file.f <->symbolTab.c:       [35]
											*write_entries_to_file.f
								[36]
				        *	write_convertBinary_table_to_file.f <->binariTab.c:           [37]
												    *write_convertBinary_table_to_file.f
								[38]
				        *	process_file.f <-> lists.c:    [39]
							[40]		   *process_file.f
					*	free_resources.f <->creatData.c    [41]
									    *free_resource.f


[1]:The program stats with file main.c [2]:Assembler function is being called [3]:Switch to assambler file [4] Called to function handleSingel
[5]:Called to function for create data structurs for prodject :hash tables macro/symbol lists:jamp entry extern ,binari tables.
[6] Switch ti creatData.c for creat structurs data [7] Called function for creat data structurs [8] Called function preAssambler for work this macro text
[9] Switch to preAssamber.c file [10] Called function preAssabler [11] Called function replays key this value for buid file  if no macro function only copy text and do am file.[12]Come bacl to assambler.c called to first_pass fuction [13]Switch to  firstRun.c file [14] Called for function parse_line [15] Switch to file lexer.c [16] Called for function parsed_line [17]Come back to file firstRun.c called to synatax_anliz [18]Switch to file syntax_analiz.c [19] Called to function syntax_analiz
[20]Come back to firstRun.c  called for function inToSymbol.c[21]Switch to file symbolTab.c [22]Called to function inToTable [23] Come back to first run and come back to assabler.c file called to second run function [24] Switch to secondRun.c file [25]Called to function parsed_line [26] Switch to lexer.c file[27]  Called to function 
[28]Come back to secondRun.c and called to analiz_operand [29] Switch to syntax_analiz file [30]Called to analiz_operand function [31]Come back to secondRun file
[31]Called to function add_to mamory[32]Switch to file memory.c[33]Called to function add_tomachin_code [34]-[39]If conditions are met files ob,ext,ent will be creat
[40]Free all structurs for prodject [41] Called to function free all structurs 

This is the serface plan for file prossessing ,most accurate information about functions and structures is in their head files
also in this file many implementation details are omitted ,but only an apporoximated algorithm and project implementation plan

PS:RAM: as it was said in the condition of the project will be able to 256 places
.We assume that the first hundred places are occupied and then in our project there are 156 free places for converting words
  

 


