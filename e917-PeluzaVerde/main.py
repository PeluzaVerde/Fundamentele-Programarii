#from repo import
#from service import
from ui import UI

from repo import Repository
from service import service
from ui import UI

file_name = "question.txt"

repository = Repository(file_name)

service = service(repository)

ui = UI(service, repository)

ui.run()







