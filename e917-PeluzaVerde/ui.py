from repo import RepoErr
from service import servErr

class UI:
    def __init__ (self, service, repository):
        self._service = service
        self._repo = repository

    def printmenu(self):
        print( "add, start, create")
    def run(self):
        self.printmenu()
        while True:
            try:
                command = input(">")

                tokens2= command.strip().split(" ")
                command_word = tokens2[0]
                cmd = tokens2[1]

                tokens = command.strip().split(";")
                command_params = tokens[0:]
                command_params2 = tokens2[1:]
                print(command_word)

                if command_word == 'add' and len(command_params) == 7:
                    #print(str(command_params[4]))
                    ids = str(command_params[0]) #add 1
                    t = ids.strip().split(" ")
                    id = int(t[1])
                    text = str(command_params[1])
                    choica = str(command_params[2])
                    choicb = str(command_params[3])
                    choicc = str(command_params[4])
                    corr = str(command_params[5])
                    diff = str(command_params[6])


                    self._service.add_question(id,text,choica,choicb,choicc,corr,diff)
                elif command_word == 'create' and len (tokens2) == 4:

                    noq =int(tokens2[2])
                    file =str(tokens2[3])
                    diff = str(tokens2[1])
                    print(diff)
                    self._service.create_quiz(diff,noq,file)
                elif command_word == 'start':
                    pass
                else:
                    raise IndexError("not a valid command")
            except (RepoErr,servErr,IndexError,TypeError) as v:
                print(str(v))




# insert_number_try2(num_list, command_params)
# split = command_params.split(';')  # insert 1+1i at 1
#         z1 = test2(split[0])
#         z2 = split[2]
#         for i in num_list:
#             index = num_list.index(i)
#             if int(index) == int(z2):
#                 # remove_number(num_list, index)
#                 number = create_complex(int(z1[0]), int(z1[1]))
#                 insert_number(num_list, number, index)
