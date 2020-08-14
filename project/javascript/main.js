

const todos = [
    {
        id:1,
        text:'take out trash',
        iscompleted: true
    },
    {
        id:2,
        text: 'meeting with boss',
        iscompleted: true
    },
    {
        id:3,
        text: 'dentist appt',
        iscompleted : false
    }
];

const todocompleted =todos.filter(function(todo){
return todo.iscompleted===true;
}).map((todo)=>{
    return todo.textzoo
});

console.log(todocompleted)